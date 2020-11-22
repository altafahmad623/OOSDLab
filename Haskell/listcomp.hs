 
{-

set builder notation 

S1 = { x | x (belongs to) N, x satisfies P / P(x) = something }

similar representation for list in Haskell
is called List Comprehension

or and || &&

-}

is_prime :: Int->Bool
is_prime 1 = False
is_prime 2 = True
is_prime n 
     | (length [x | x<- [2..n-1], mod n x ==0]  >0 ) = False
     | otherwise = True

main = do 
    let l1 = [20, 18.. 6] -- considers numbers till the last number, with common difference indicated by first two numbers
    let l2 = []
    let l3 = [3,2,10,7,41,8,13]
    let l4 = [7.2,3.0,4.7, 1.24,5.5, 5.6]
 --   print $ [ x*x | x <- l3 , mod x 2 == 0] -- list of squares of x, such that x comes from l3, and x mod 2 is 0 i.e. x is even
 --   print $ [ x*x | x <- [1..20] , mod x 2 == 0]
--    print $ [(x,y) | x <- [1..5], y <- [1..5]]
 --   print $ [(x,y,z) | x<-[1..100],y<-[1..100],z<-[1..100], x<y, x*x + y*y == z*z]
  --  print $ [x | x <- [1..100], mod 100 x == 0]
  --  print $ [x | x <- [1..20], (mod x 2 == 0) || (mod x 3 == 0)]
 --   print $ is_prime 100
 --   print $ [x |x<- [1..n], is_prime x == True]
    print $ sieve [2..n]
    where 
        n = 50000
        sieve [] = []
        sieve (x:xs) = x:(sieve [y |  y <- xs, mod y x >0])
 --   print $ l1
 --   print $ take 3 l3
  --  print $ drop 3 l3
 
