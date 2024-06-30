const std = @import("std");

// zig build-exe hello_again.zig
pub fn main() void {
    std.debug.print("Hello, world!\n", .{});
}
