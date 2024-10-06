const std = @import("std");
const User = struct {
    id: usize,
    name: []const u8,
    pub fn init(id: usize, name: []const u8) User {
        return .{ .id = id, .name = name };
    }
};

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocotor = gpa.allocator();
    const user = try allocotor.create(User);
    defer allocotor.destroy(user);

    user.* = User.init(0, "PPP");

    std.debug.print("User name is {s}", .{user.*.name});
}
