data Nat = Zero | Succ Nat 

data SInt = Sint Nat Bool       -- 0 = plus, 1 = minus

plusNat :: Nat -> Nat -> Nat 
plusNat m Zero = m 
plusNat m (Succ (n)) = Succ (plusNat m n)

multNat :: Nat -> Nat -> Nat 
multNat m Zero = Zero
multNat m (Succ n) = plusNat m (multNat m n)  -- m ( n + 1) = m + m*n

minusNat :: Nat -> Nat -> Nat
minusNat m Zero = m
minusNat (Succ m) (Succ n) = minusNat m n  

convtointNat :: Nat -> Int -- convert to int
convtointNat Zero = 0  -- converts Zero (which is user defined) to actual 0
convtointNat (Succ n) = 1 + (convtointNat n)

plus :: SInt -> SInt -> SInt
plus (Sint a1 s1) (Sint a2 s2) 
    | s1 == s2 = Sint (plusNat a1 a2) s1 
    | convtointNat(a1) > convtointNat(a2) = Sint (minusNat a1 a2) s1
    | otherwise = Sint (minusNat a2 a1) s2

sn :: Bool -> Bool -> Bool
sn s1 s2
    | s1 == s2 = False
    | otherwise = True

mult :: SInt -> SInt -> SInt
mult (Sint a1 s1) (Sint a2 s2) = (Sint (multNat a1 a2) (sn s1 s2))

minus :: SInt -> SInt -> SInt
minus n1 (Sint a2 s2) = plus n1 (Sint a2 (not s2))

convtoint :: SInt -> Int
convtoint (Sint a False) = convtointNat a
convtoint (Sint a True) = -1*convtointNat a

main = do
    let x = (Sint (Succ (Succ Zero)) True) 
    let y = (Sint (Succ (Succ Zero)) False)
    let a = plus x y 
    let b = minus x y
    let c = mult x y
    print $ convtoint (a)
    print $ convtoint (b)
    print $ convtoint (c)
 