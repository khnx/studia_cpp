# Complex Numbers

## Format

  (re, im)

  where:
  re - real part,
  im - imaginary part;
  
  Both parts consist of only real numbers. Imaginary unit is being kept track of separately. Imaginary unit can be in only one state:

      1. present
      2. absent

  If multiplying two complex numbers yeld a number of form (x, y), that doesn't have an imaginary unit, the second input ought to be transferred to the real part.

## Operations

1. Addition

      `(a, bi) + (c, di) = (a+c, (b+d)i)`

2. Substraction

      `(a, bi) - (c, di) = (a-c, (b-d)i)`

3. Multiplication

      `(a, bi)(c, di) = (ac - bd, (ad + bc)i)`

4. Division

      `(a, bi)/(c, di) = (a + bi)(c - di)/(c^2 + d^2)`
      `((ac - bd) / (c^2 + d^2), ((ad + bc) / (c^2 + d^2)) i)`

## Functions

1. Complex conjugate number
2. Euclidean norm
3. Square euclidean norm
4. Argument function