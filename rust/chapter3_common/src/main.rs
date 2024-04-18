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
}

