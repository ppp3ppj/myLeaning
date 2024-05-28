package aggregate

import (
	"errors"
	"impl-ddd/entity"
	"impl-ddd/valueobject"

	"github.com/google/uuid"
)

var (
    ErrInvalidPerson = errors.New("a customer has to have a valid name")
)

type Customer struct {
    // peson is the root entity of customer
    // which mean person.Id is the main identifier for the customer

    person *entity.Person
    products []*entity.Item
    transactions []valueobject.Transaction // not ptr cause it imutable - valueobject
}

// NewCustomer is a factory to create a new customer aggregate
// validate that the name is not empty
func NewCustomer(name string) (Customer, error) {
    if name == "" {
        return Customer{}, ErrInvalidPerson
    }

    person := &entity.Person{
        Name: name,
        Id: uuid.New(),
    }

    return Customer{
        person: person,
        products: make([]*entity.Item, 0),
        transactions: make([]valueobject.Transaction, 0),
    }, nil
}
