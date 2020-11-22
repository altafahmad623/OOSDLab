collapse :: [[Int]] -> [Int]
collapse [x] = x
collapse (x:xs) = x ++ collapse xs -- this adds the list one by one from the beginning

main = print $ collapse  [[5,1],[6,9,10,5],[9,2,4]]