quicksort :: [Int] -> [Int]
quicksort []     = []
quicksort (x:xs) = (quicksort smaller) ++ [x] ++ (quicksort greater)
    where
        smaller  = filter (< x) xs
        greater = filter (>= x) xs
smallerPivot :: Int-> [Int] -> [Int] -> [Int]
smallerPivot pivot xs [] = xs
smallerPivot pivot xs (ct:cts) | ct <= pivot = smallerPivot pivot (xs++[ct]) cts
                               | ct > pivot = smallerPivot pivot xs cts

largerPivot :: Int-> [Int] -> [Int] -> [Int]
largerPivot pivot xs [] = xs
largerPivot pivot xs (ct:cts) | ct > pivot = largerPivot pivot (xs++[ct]) cts
                              | ct <= pivot = largerPivot pivot xs cts
    
main = do
    let li = [5,1,8,2,9,4,7,3]
    print $ quicksort li