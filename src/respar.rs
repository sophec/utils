use std::env;
use std::process::exit;

fn usage(argv0: &str) {
    eprintln!("usage: {} R1 [R2...]", argv0);
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        usage(&args[0]);
        exit(1);
    }

    let mut sum = 0.0f64;

    for arg in &args[1..] {
        let r = arg.parse::<f64>().unwrap();
        sum += 1.0 / r;
    }

    println!("equivalent resistance: {} Ohms", 1.0 / sum);
}
