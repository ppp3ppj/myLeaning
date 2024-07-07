const std = @import("std");

// if return false will fail when run zig test .. this file.
test "expect this to fail" {
    try std.testing.expect(false);
}

test "expect this to successed" {
    try std.testing.expect(true);
}
