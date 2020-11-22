len :: [Int] -> Int -- provides the length of the list
len [] = 0
len (x:xs) = 1 + len(xs)

isTaxiCab :: Int -> [(Int, Int)]
isTaxiCab a | length [(p,q) | p<-[1..a], q<-[1..a], z<-[a], z == p*p*p+q*q*q, p<q] > 1 = [(p,q) | p<-[1..a], q<-[1..a], z<-[a], z == p*p*p+q*q*q, p<q] -- checks if the length of the list is greater that 1, that is there are more than 1 elements in the list of the cube sum
    |otherwise = []

main = do
    print $ isTaxiCab 4104