package valueobject

import (
	"time"
	"github.com/google/uuid"
)

// Transaction is a valueobj cause it has no identifier an is immutable
type Transaction struct {
    amount int
    from uuid.UUID
    to uuid.UUID
    createdAt time.Time
}
