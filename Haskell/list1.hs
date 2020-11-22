

newlength :: [Integer] -> Integer
newlength [] = 0
newlength (x:xs) = 1 + newlength xs

{-

newlength (6 : [8,10,12]) = 1 + newlength (8 : [10,12]) = 1 + (1 + newlength (10: [12])) = 1 + (1 + (1  + newlength (12 : [])))

= 1 + (1 + (1  + (1 + newlength []))) =  1 + (1 + (1  + (1 + 0))) =  1 + ( 1 + (1 + 1)) = 1 + ( 1 + (2))
= 1 + 3 = 4 


-}

newhead :: [b] -> b        -- user defined head function
newhead [] = error "List has no head"
newhead (x:xs) = x

newtail :: [a] -> [a]
newtail [] = []
newtail (x:xs) = xs

newreverse:: [a] -> [a]
newreverse []=[]         
newreverse(x:xs) = newreverse(xs)++[x]       

newlast :: [Integer] -> Integer
newlast[ ] = error "Empty list"
newlast[x] = x
newlast(x : xs) = newlast xs 

newinit :: [Integer] -> [Integer]
newinit [] = error "List empty"
newinit [x] = []
--newinit [x,y] = [x]
newinit (x:xs) = [x] ++ newinit(xs)

{-

newadd :: Integer -> Integer -> Integer
x newadd y = x + y

Invoking functions in an infix manner is not allowed, because normally we write the function name before that of the operands.

-}

access :: [a] -> Integer -> a
access [] idx = error "Index out of bounds !!" -- if the list is empty then no index makes sense
access (x : xs) 0 = x                -- if the index is 0, then we just take the head 
access (x : xs) idx = access xs (idx - 1) -- here the list is divided into two parts
-- this works, because essentially we are throwing away the first element of the list, and decreasing the index by 1

newsum :: [Integer] -> Integer
newsum [] = 0
-- newsum [x] = x
newsum(x:xs) = x + newsum(xs)

power :: Float -> Integer -> Float
power x 0 = 1
power x n = x * (power x (n-1))


new_split_helper :: [Integer] -> Integer -> [Integer] -> ([Integer], [Integer])
new_split_helper l1 0 xs = (l1, xs)
new_split_helper l1 idx (x : xs) = new_split_helper (l1 ++ [x]) (idx - 1) xs
 
newsplitAt :: Integer -> [Integer] -> ([Integer], [Integer])
newsplitAt idx l1 = new_split_helper [] idx l1

newsplit :: Integer -> [Integer] -> ([Integer], [Integer])
newsplit 0 x = ([],x)
newsplit n (x:xs) = (x:xs', xs'')
 where
 	(xs', xs'') = newsplit (n-1) xs

main = do 
    let l1 = [6,8..20] -- considers numbers till the last number, with common difference indicated by first two numbers
    print $ newreverse l1
    print $ reverse [1..10]
    print $ reverse [1.0..10.0]
    print $ reverse ['a'..'e']
    print $ newreverse [1.0..10.0]
    print $ newreverse ['a'..'e']
    print $ newhead ['a'..'e']
    print $ newtail ['a'..'e']
    print $ access ['a'..'e'] 2
    print $ newsplitAt 2 l1 
    print $ newsplit 2 l1
 --   print $ [1..]
 --   print $ head [1..] -- head is printed because haskell does not compute the whole list
    {-
    print $ l1
    print $ x + y
    print $ (+) x y
    print $ x - y
    print $ x * y
    print $ mod x y
    print $ a / b
 --   print $ div x y -- stops computation if division by zero occurs
    print $ x ^ y
    print $ (div x y) ^ 0
 --   print $ power x y 
 --   print $ power 5 0
--    print $ power (a/b) 0
    print $ power (3.0/0.0) 0
  --  print $ power (div 3 0) 1 -- second argument = 0 gives 1, second argument != 0 gives an error
    print $ div 3 0
    where x = 2
          y = 3 
          a = 16.0
          b = 5.0

          -}
          


    {-
    print $ init l1
    print $ newinit l1
    print $ l1 !! 3  -- double exclamation k accesses the element at the kth index of the list (in LINEAR time)
    print $ (!!) l1 3 -- putting the operator in brackets allows it to be used like a function, the function name followed by operand 
    print $ access l1 3 
    print $ sum l1 
    print $ 4 + 5 
    print $ (+) 4 5
    print $ newsum l1
    print $ splitAt 3 l1 
    print $ splitAt 0 l1
    -}




     {-}   
	print $ l1 
	print $ l1 ++ [49,50] -- concatenates lists
	print $ length l1
	print $ newlength l1
	print $ head l1
	print $ newhead l1
	print $ tail l1
	print $ newtail l1
	print $ reverse l1
	print $ newreverse l1
	print $ last l1
	print $ head (reverse l1) -- same as last
	print $ newlast l1
	print $ init l1 
	-}





-- main = putStrLn "Hello World!"