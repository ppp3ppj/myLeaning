fn main() {
    //------ Variables and Mutability ------
    // cannot assign twice cause x is immutable variable
    /*
    let x = 5;
    println!("The vaule of x is {x}");
     = 6;
    println!("The vaule of x is {x}");
    */

    // can assign again x is mutable variable
    let mut x = 5;
    println!("The vaule of x is {x}");
    x = 6;
    println!("The vaule of x is {x}");

    //------ Constants ------
    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3; // it can first init only [immutable]
    println!("The vaule of constants is {THREE_HOURS_IN_SECONDS}");

    //------ Shadowing ------
    // can declare a new variable with the same name as a previous variable it call shadowed in
    // rust

    let y = 5;
    let y = y + 1; // shadowed from above
    println!("address of y is: {:p}", &y);
    {
        let y = y * 2; //shadowed from above but in lifetime only inner scope = {}
        println!("The vaule of y in the inner scope is: {y}");
        println!("address of y[inner] is: {:p}", &y);
    }
    println!("The vaule of y is: {y}");

    let spaces = "    ";
    let spaces = spaces.len();
    println!("The spaces len is: {spaces}");

    // it mismatched types &str but len return usize
    /*
        let mut spaces = "    ";
        spaces = spaces.len();
    */

    //------ Data Types ------
    let guess: u32 = "42".parse().expect("Not a number");
    // Scalar Type : pepresents a single vaule. rust has four primary scalar types: integers,
    // floating-point numbers, Booleans, and characters.
    //
    //let int_overflow: u8 = 256; it //error integer overflow because u8 ragnge is 0..=255

    let xx = 2.0; // f64
    let yy: f32 = 3.0; //f32
    let sum = 6 + 10;

    let difference = 95.5 - 4.3;
    let product = 4 * 30;

    let quotient = 56.5 / 32.2;
    let truncated = -5 / 3;
    let remainder = 43 % 5;

    let t = true;
    let f: bool = false; // with explicit type annotation

    let c = 'Z';
    let z: char = 'Z'; // with explicit type annotation
    let heart_eyed_cat = 'e'; // storing utf-8 encoded text with string in chapter 8
    // ---- Tuple type ----
    let tup: (i32, f64, u8) = (500, 3.48, 8);
    let extup = (400, 3.44, 8);
    let tub_a = (600, 6.4, 1);
    let (xxx, yyy, zzz) = tub_a;
    println!("The vaule of yyy is: {yyy}");


    // tuple index . to access each element
    let x: (i32, f64, u8) = (500, 6.4, 1);
    let five_hundred = x.0;
    let six_point_four = x.1;
    let one = x.2;

    // ---- Array tuple ----
    let a = [1, 2, 3, 4, 5]; // array of i32
    // array of &str
    let months = ["Jan", "Feb", "Mar", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    // array of i32 and set lenght is 5
    let a: [i32; 5] = [1, 2, 3, 4, 5];

    // or this
    // // 3 is initial vaule
    // it same to writting let a = [3, 3, 3, 3, 3];
    let a = [3; 5]; // it mean in array have 3 all member and lenght is 5 equal above

    // ---- functions ----
    another_function();
    // parameters
    another_function_params(13);
    // statements and expressions
    // -- statements are instruction that perform some action and do not return a value
    // -- expressions evaluate to a resultant vaule.

    // function with return values
    let five_num = five();

    // ---- Comments ----
    // this is comment in rust

}

fn five() -> i32 {
    5
}

fn another_function() {
    println!("Another function.");
}
fn another_function_params(x: i32) -> () {
    println!("The vaule of x is {}", x);
    println!("The vaule of x is {x}");
}
