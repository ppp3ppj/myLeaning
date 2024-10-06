const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    var aa = std.heap.ArenaAllocator.init(gpa.allocator());
    defer aa.deinit();

    const allocator = aa.allocator();

    const in1 = allocator.alloc(u8, 5);
    const in2 = allocator.alloc(u8, 10);
    const in3 = allocator.alloc(u8, 15);
    _ = try in1; _ = try in2; _ = try in3;
}

