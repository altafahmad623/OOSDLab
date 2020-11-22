-- Name : Altaf Ahmad, Roll no: 18MA20005
data BinaryTree a = Empty | Node (BinaryTree a) a (BinaryTree a)

maxim_t ::Int->Int->Int
maxim_t  x y = if x>y then x
                else y

tree_ht:: BinaryTree Int->Int
tree_ht  Empty = 0
tree_ht  (Node left x right) = maxim_t  ((tree_ht left )+1) ((tree_ht right)+1)

bst::BinaryTree Int->Int->[Int]
bst Empty i = []
bst (Node left x right) 1 = [x]
bst (Node Empty x right) i = bst right (i-1)
bst (Node left x Empty) i = bst left (i-1) 
bst (Node left x right) i = bst left (i-1) ++ bst right (i-1)

printbst:: Int->Int->BinaryTree Int->[Int]
printbst i h t  = if(i<=h) then bst t i ++ printbst (i+1) h t
                  else []

main = do
     let t =(Node (Node (Node Empty 7 Empty) 5 (Node Empty 3 Empty)) 6 (Node (Node Empty 9 Empty) 4 Empty))
     let h = tree_ht t
     print $ h 
     print $ printbst 1 h t
