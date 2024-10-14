//! By convention, root.zig is the root source file when making a library. If
//! you are making an executable, the convention is to delete this file and
//! start with main.zig instead.
const std = @import("std");
const testing = std.testing;

export fn add(a: i32, b: i32) i32 {
    return a + b;
}

test "basic add functionality" {
    try testing.expect(add(3, 7) == 10);
}

fn bubbleSort(list: []i32) void {
    const unsorted_until_index = list.len - 1;
    var sorted: bool = false;

    while (!sorted) {
        sorted = true;
        for (0..unsorted_until_index) |elem| {
            if (list[elem] > list[elem + 1]) {
                sorted = false;
                std.mem.swap(i32, &list[elem], &list[elem + 1]);
            }
        }
        //unsorted_until_index = unsorted_until_index - 1;
    }
}

test "basic bubble sort functionality" {
    //var list = [_]i32{ 65, 55, 45, 35, 25, 15, 10 };
    var list = [3]i32{ 2, 8, 1 };
    bubbleSort(&list);
    for (0..list.len) |i| {
        std.debug.print("{d}\n", .{list[i]});
    }
}
