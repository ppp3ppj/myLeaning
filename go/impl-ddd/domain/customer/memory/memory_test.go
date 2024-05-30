package memory

import (
	"errors"
	"impl-ddd/aggregate"
	"impl-ddd/domain/customer"
	"testing"

	"github.com/google/uuid"
)

func TestMemory_GetCustomer(t *testing.T) {
    type testCase struct {
        name string
        id uuid.UUID
        exepectedErr error
    }

    cust, err := aggregate.NewCustomer("percy")
    if err != nil {
        t.Fatal(err)
    }

    id := cust.GetId()

    repo := MemoryRepository{
        customers: map[uuid.UUID]aggregate.Customer{
            id: cust,
        },
    }

    testCases := []testCase{
        {
            name: "no customer by id",
            id: uuid.MustParse("d203bc0f-b9b8-4992-a7a5-b8de1122b6c7"),
            exepectedErr: customer.ErrCustomerNotFound,
        },
        {
            name: "customer by id",
            id: id,
            exepectedErr: nil,
        },
    }

    for _, tc := range testCases{
        t.Run(tc.name, func(t *testing.T) {
            _, err := repo.Get(tc.id)

            if !errors.Is(err, tc.exepectedErr) {
                t.Errorf("expected error %v, got %v", tc.exepectedErr, err)
            }
        })
    }
}
