quicksort :: [Int] -> [Int]
quicksort []     = []
quicksort (x:xs) = (quicksort smaller) ++ [x] ++ (quicksort greater) --first it takes all the elements less than x and puts it before it and all the elements greater than x after it
    where
        smaller  = [l | l<-xs, l <= x]
        greater = [r | r<-xs, x < r ]

main = do
    let li = [5,1,8,2,9,4,7,3]
    print $ quicksort li