const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    const some_number = try allocator.create(u32);
    const stdout = std.io.getStdOut().writer();
    defer allocator.destroy(some_number);

    some_number.* = @as(u32, 45);
    try stdout.print("some_number is {d}\n", .{some_number.*});
}
