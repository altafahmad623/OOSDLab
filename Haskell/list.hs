newlength :: [Int] ->  Int
newlength [] = 0
newlength (x:xs) = 1 + newlength xs

newhead :: [Int] -> Int
newhead [] = 0
newhead (x:xs) = x

new_split_helper :: [Integer] -> [Integer] -> Integer -> ([Integer], [Integer])
new_split_helper l1 (x : xs) 0 = (l1 ++ [x], xs)
new_split_helper l1 (x : xs) idx = new_split_helper (l1 ++ [x]) xs (idx - 1)

cubeRoot :: Double -> Int
cubeRoot n= floor((iterate(\x->(x+n/x/x)/2)n)!!99)

new_split :: [Integer] -> Integer -> ([Integer], [Integer])
new_split l1 idx = new_split_helper [] l1 idx

main = do
    let li = [6,8..20]
    let l2 = []
    --print $ li
    --print $ li ++[49,50]
    --print $ length li
    --print $ newlength li
    --print $ head li
    --print $ newhead li
    --print $ newhead l2
    print $ cubeRoot(366)
