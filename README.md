# Camille's Chaotic Contrivances when Crafting C

### What's here ?
You'll find a collection of the small programs I wrote to better myself at learning C. Most of them can be compiled anywhere you have a C compiler and standard libraries, for example on your standard, run-of-the-mill Linux distribution. So basically : 
```
gcc whatever.c -o whatever
```

##### Fibonacci
sha256 - b833665a505f77679e0cf56bdf62569d97de2af2aa3f5a969a6441f1f6bbae53

A simple implementation of the fibonacci sequence born from me growing mad with power when I actually started to grasp how much **faster** C is compared to the other languages I am used to.
This one's pretty simple to use. Run it, and you'll be prompted for the amount of iterations you wish to do. Enter an integer, and let it rip !
Just remember, the bigger the amount of iterations, the longer it'll take.

##### Fizzbuzz
sha256 - afc754bd812e8bc08b883e9f5f7e09fbac021eef9ba8c84baa8d46299ad1679c

Another simple one, where you need to iterate through 0 to *n* numbers, printing *fizz* when the current number is divisible by 3, and *buzz* when it's divisible by 5.
This one is less interactive. You just run it, and it runs for all numbers from 0 to 100.

##### Pi
sha256 - 1bf6f8d1b27de7e6beea21bc89830f5d6b7fbd016c0c565e19f79f2d061bbfe4

This one's probably my favorite. It's an implementation of the [**Chudnovsky Algorithm**](https://en.wikipedia.org/wiki/Chudnovsky_algorithm), used to calculate Pi. It's probably not the fastest nor the best implementation, but I had fun with it, and for some reason calculating Pi gave me a rush of adrenaline.
To use it, you'll need to provide the amount of iterations you want it to go through as an argument :
```
./pi 42 # This'll calculate 42 iterations of the Chudnovsky Algorithm.
```

##### Reverse-a-string
sha256 - 9b6bd42f711d2e3637ce41ce19fe68808483781978970c4c451b415a981784f0

That fella is pretty simple, just reverses a string you gave it. 
Just run it, and it'll ask for the string you wish to reverse before providing it back(wards) to you.

##### Sort-stuff 
sha256 - 22ca2948ef4a90ea63792b60e2c2e81b39bc40acc3e6d4ba73f7e6229718b7d1

An implementation of the quick sort algorithm. When run, it'll ask for numbers. You can give it up to 128 integers (Can be changed in the code), and start sorting by pressing enter on an empty input.
You'll get the sorted result fairly quickly.
