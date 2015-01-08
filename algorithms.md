Every Brainfucj beginner immediately encounters the following problems: 

- The lack of the copy value operation. 
- The lack of accumulation memory. 
- The lack of normalized boolean operators. 
- The lack of normal arithmetic, operations for multiplication and division. 

This is an algorithm catalogue to solve these and many other problems. 

## @(k)

Goto k cells right. 

```
if k > 0
    then
        times k >
    else
        times (k + (k * 2)) <
end
```

## zero()

Nil the current cell. 

```
[-]
```

## add(k)

Add value of the current cell to value of (n + k). 

```
[- @(k) + @(-k)]
```

**Against**: value of the current cell is nilled, too. 

## mov(k)

Copy value of the current cell to (the current cell + k). Value of the current cell is nilled. 

```
@(k) zero() @(-k) add(k)
```

## copy(k, t)

Copy value of the current cell to (the current cell + k). Uses a medium (the current cell + k + t) to leave value of n intact. 

```
@(k) zero() @(t) zero() @(-k-t) [— @(k) + @(t) + @(-k-t)] @(k+t) mov(-k-t)
```

## if(t)

If the current cell > 0, execute the code. Uses a medium (the current cell + t). 

```
@(t) zero() @(-t) [
code
@(t)
] @(-t)
```

## outn()

Print value of current cell as number. 

```
>++++++++++<<[->+>-[>+>>]>[+[-<+>]>+>>]<<<<<<]>>[-]>>>++++++++++<[->-[>+>>]>[+[-
<+>]>+>>]<<<<<]>[-]>>[>++++++[-<++++++++>]<.<<+>+>[-]]<[<[->-<]++++++[->++++++++
<]>.[-]]<<++++++[-<++++++++>]<.[-]<<[-<+>]
```

Answer taken from [Stack Overflow](http://stackoverflow.com/questions/12569444)

## The power series

```
Sum(aN * b^N where N=0..Infinity) => [ a0 * b^0 + a1 * b^1 + a2 * b^2 + a3 * b^3 + ... ]
```

Probably the simplest way of generating any number in Brainfucj with a reasonably short instruction string. This is (after all) the way that normal decimal numbers are represented.

Assuming we're using base 10 the core fragment is this `[>++++++++++<-]>` with its mirror image `[<++++++++++>-]<`. This fragment simply multiplies the current cell by 10. So take your decimal number, say: `45306`, divide it up into the power series like this:

```
((( 4 *10 +5 ) *10 +3 ) *10 +0 ) *10 +6
```

Then just convert to Brainfucj!

```
++++[>++++++++++<-]>+++++[<++++++++++>-]<+++[>++++++++++<-]>[<++++++++++>-]<++++++
1234  *10           12345  *10           123  *10             *10           123456
```

Notice the current cell flips between the two that are being use so we use the two multipliers alternately.

The method does not need to wrap and only ever uses two cells. 
