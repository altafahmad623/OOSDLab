quicksort :: [Int] -> [Int]
quicksort []     = []
quicksort (x:xs) = (quicksort smaller) ++ [x] ++ (quicksort greater)
    where
        smaller  = filter (< x) xs
        greater = filter (>= x) xs

main = do
    let li = [5,1,8,2,9,4,7,3]
    print $ quicksort li