f x y z | x == y^3 + z^3 = True
        | otherwise = False

g :: Int -> Int -> Int -> [(Int, Int)] -> [(Int, Int)]
h :: Int -> Int -> [(Int, Int)] -> [(Int, Int)]
p :: Int -> [(Int, Int)]
len :: [(Int, Int)] -> Int

g x y z [] | f x y z =  [(y,z)] 
           | y^3 > x = []
           | z == 1 = []
           | otherwise = g x y (z-1) []

g x y z (a:as) = let ans = g x y z []
                 in [a]++as++ans

h x 0 as = as
h x y as = let ans = g x y y as
               ans2 = h x (y-1) as
           in ans ++ ans2 ++ as

p x = h x x []

len [] = 0
len (x:xs) = len xs + 1

final x | len (p x) == 2 = show (p x)
        | otherwise = "The number does not sum up as two cubes of two distinct numbers"
main = print (final 1729)