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
