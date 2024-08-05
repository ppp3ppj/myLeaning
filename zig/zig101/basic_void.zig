const print = @import("std").debug.print;

fn diff(a: u32, b: u32) !u32 {
    if (b > a)
        return error.NoWay;
    return a - b;
}

pub fn main() !void {
    const x = try diff(7, 5);
    print("x = {}\n", .{x});
    const y = try diff(5, 7);
    print("y = {}\n", .{y});
}
