# Complex Numbers

## Format

  (re, im)

  where:
  re - real part,
  im - imaginary part;
  
  Both parts consist of only real numbers. Imaginary unit is being kept track of separately. Imaginary unit can be in only one state:

  * present
  * absent

  If multiplying two complex numbers yeld a number of form (x, y), that doesn't have an imaginary unit, the second input ought to be transferred to the real part.

## Operations

* Addition

(a, bi) + (c, di) = (a+c, (b+d)i)

* Substraction

(a, bi) - (c, di) = (a-c, (b-d)i)

* Multiplication

(a, bi)(c, di) = (ac - bd, (ad + bc)i).

* Division

(a, bi)/(c, di) = (a + bi)(c - di)/(c^2 + d^2).
((ac - bd) / (c^2 + d^2), ((ad + bc) / (c^2 + d^2)) i)

## Functions

* Complex conjugate number
* Euclidean norm
* Square euclidean norm
* Argument function