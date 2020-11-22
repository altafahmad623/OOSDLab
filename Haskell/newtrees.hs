

data Btree a = Empty | Node (Btree a) a (Btree a)

flatten :: Btree a -> [a]
flatten Empty = []
flatten (Node lt x rt) = (flatten lt) ++ [x] ++ (flatten rt)


is_bst :: Btree Int -> Bool
is_bst (Node Empty x Empty) = True
is_bst (Node Empty x (Node rlt rv rrt)) = (is_bst (Node rlt rv rrt)) && (x <= rv) -- comparison with right value and right subtree
is_bst (Node (Node llt lv lrt) x Empty) = (is_bst (Node llt lv lrt)) && (lv <= x) -- ditto with left
is_bst (Node (Node llt lv lrt) x (Node rlt rv rrt)) 
= (is_bst (Node llt lv lrt)) && (is_bst (Node rlt rv rrt)) && (lv <= x) && (x <= rv) -- comparison with both


    
isincreasing :: (Ord a) => [a] -> Bool
isincreasing [] = True
isincreasing [_] = True
isincreasing (x : y : xs) = (x <= y) && (isincreasing (y : xs))

isbst :: (Ord a) => Btree a -> Bool
isbst Empty = True
isbst t = isincreasing (flatten t)



insertbst::Int-> Btree Int -> Btree Int
insertbst y (Node Empty x Empty)
|y<=x = (Node (Node Empty y Empty) x Empty)
|otherwise = (Node Empty x (Node Empty y Empty))
insertbst y (Node (Node llt lx lrt) x Empty)
|y<=x = insertbst y (Node llt lx lrt)
|otherwise = (Node (Node llt lx lrt) x (Node Empty y Empty))
insertbst y (Node Empty x (Node rlt rx rrt))
|y>x = insertbst y (Node rlt rx rrt)
|otherwise = (Node (Node Empty y Empty) x (Node rlt rx rrt))
insertbst y (Node(Node llt lx lrt) x (Node rlt rx rrt))
|y<=x = insertbst y (Node llt lx lrt)
|otherwise = insertbst y (Node rlt rx rrt)

{-

1) Base case is for empty tree, or node with one or more empty singleton children
2) For the last two cases, you might have to compare
3) ultimately recurse down the left and right subtree of each node


For deleting a value x from a given tree
1) locate x in the tree
2) in the subtree with root x, find the largest value in its left subtree or smallest value in its right subtree,
and substitute in place of x.


-}

main = do
 let l1 = [1..5]
 let t1 = Node Empty 5 Empty
 let t2 = Node (Node (Node Empty 3 Empty) 5 (Node Empty 4 Empty)) 6 (Node Empty 7 Empty)
 print $ l1
 print $ flatten t2
 print $ flatten t1