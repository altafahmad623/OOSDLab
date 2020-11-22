import Data.Array

fib = 1: 1: [a+b | (a,b) <- zip fib (tail fib)]

array1 = listArray (0,4) ['g','h','a','b','c']

array2 = listArray ('a', 'd') [1..]

array3 = listArray (5,9) ['a','b','c','d','e']

multTable = [[x*y | x <- [1..10] ] | y<- [1..10]]

addMe :: Integer -> Integer -> Integer
addMe a b = a + b

factorial :: Integer -> Integer
factorial 0 = 1
factorial x = (x)*factorial (x-1)

main = do
    let li = [1,2..5]
    --print $ li
    --print $ array1
    --print $ array2
    --print $ array3
    --print $ multTable
    --print $ addMe 2 3
    print $ fib !! 300