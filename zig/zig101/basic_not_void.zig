const print = @import("std").debug.print;

fn diff(a: u32, b: u32) u32 {
    return a - b;
}

pub fn main() void {
    const x = diff(7, 5);
    print("x = {}\n", .{x});
    const y = diff(7, 5);
    print("y = {}\n", .{y});
}
