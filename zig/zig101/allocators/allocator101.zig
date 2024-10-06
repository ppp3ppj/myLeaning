const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    const name = "Pedro";
    const stdout = std.io.getStdOut().writer();
    const output = try std.fmt.allocPrint(
        allocator,
        "Hello {s}!!!",
        .{name},
    );
    try stdout.print("{s}\n", .{output});
}
