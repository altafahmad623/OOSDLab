len :: [Int] -> Int
len [] = 0
len (x:xs) = 1 + len(xs)

greater_cube :: Int -> Int 
greatercube  0 = 1
greatercube  1 = 2
greater_cube i n
    | i^3 > n = i
    | otherwise = greater_cube (i+1) n

isTaxiCab :: Int -> [(Int, Int)]
isTaxiCab a | length [(p,q) | p<-[1.. greater_cube a], q<-[1.. greater_cube a], z<-[a], z == p*p*p+q*q*q, p<q] > 1 = [(p,q) | p<-[1..a], q<-[1..a], z<-[a], z == p*p*p+q*q*q, p<q]
    |otherwise = []

main = do
    print $ isTaxiCab 1729