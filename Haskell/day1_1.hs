val :: Int
val = 25

mult2 :: Int -> Int
mult2 x = 2*x

summation :: Int -> Int -> Int
summation x y = x+y

fact :: Int -> Int
fact 0 = 1
fact x
	|x > 0 = x * fact (x-1)
	|x < 0 = fact(-x)

fib 1 = 1
fib 2 = 1
fib x = fib(x-1) + fib(x-2)

main = do
	print $ val
	print $ mult2 x
	print $ summation x y
	print $ fib x
	where (x,y,z) = (11,4,-1)

