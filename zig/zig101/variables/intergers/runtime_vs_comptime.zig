// in this fn values a and b are known only at runtime, and thus this divition
// operation is vulnerable to both integer overflow and divide by zero.
fn devide(a: i32, b: i32) i32 {
    return a / b;
}
