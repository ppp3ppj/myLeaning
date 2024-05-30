// package memory is a in-memory impl of customer
package memory

import (
	"fmt"
	"impl-ddd/aggregate"
	"impl-ddd/domain/customer"
	"sync"

	"github.com/google/uuid"
)

type MemoryRepository struct {
    customers map[uuid.UUID]aggregate.Customer
    sync.Mutex
}

func New() *MemoryRepository{
    return &MemoryRepository{
        customers: make(map[uuid.UUID]aggregate.Customer),
    }
}

func (mr *MemoryRepository) Get(id uuid.UUID) (aggregate.Customer, error) {
    if customer, ok := mr.customers[id]; ok {
        return customer, nil
    }
    return aggregate.Customer{}, customer.ErrCustomerNotFound
}

func (mr *MemoryRepository) Add(c aggregate.Customer) error {
    if mr.customers == nil {
        mr.Lock()
        mr.customers = make(map[uuid.UUID]aggregate.Customer)
        mr.Unlock()
    }
    // Make sure customer is already in repo
    if _, ok := mr.customers[c.GetId()]; ok {
        return fmt.Errorf("customer already exists :%w", customer.ErrFailedToAddCustomer)
    }
    mr.Lock()
    mr.customers[c.GetId()] = c
    mr.Unlock()
    return nil
}

func (mr *MemoryRepository) Update(c aggregate.Customer) error {
    if _, ok := mr.customers[c.GetId()]; !ok {
        return fmt.Errorf("customer does not exist: %w", customer.ErrUpdateCustomer)
    }

    mr.Lock()
    mr.customers[c.GetId()] = c
    mr.Unlock()
    return nil
}
