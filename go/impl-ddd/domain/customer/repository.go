package customer

import (
	"errors"
	"impl-ddd/aggregate"

	"github.com/google/uuid"
)

var (
    ErrCustomerNotFound = errors.New("the customer was found in the repository")
    ErrFailedToAddCustomer = errors.New("failed to add the customer")
    ErrUpdateCustomer = errors.New("failed to update the customer")
)

type CustomerRepository interface {
    Get(uuid.UUID) (aggregate.Customer, error)
    Add(aggregate.Customer) error
    Update(aggregate.Customer) error
}



