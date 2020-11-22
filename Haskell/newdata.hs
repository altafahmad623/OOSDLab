{-Nat is the new data type and the starting letter of this name is a -}
data Nat = Zero | Succ Nat -- 1st it can be 0 or succ of Nat number
    deriving Show

plus :: Nat -> Nat -> Nat
plus x Zero = x
plus Zero x = x
plus n (Succ (m)) = Succ (plus n m) -- reccursion def of plus function using succ function

{-
plus (Succ (Succ Zero) )  (Succ (Succ (Succ Zero) ))

= Succ ( plus  Succ (Succ Zero)    (Succ (Succ Zero) )     )

= Succ ( Succ ( plus  Succ (Succ Zero)   (Succ Zero)  ))


= Succ ( Succ ( Succ  (plus    Succ (Succ Zero)     Zero    ) ))

= Succ ( Succ ( Succ  (     Succ (Succ Zero)        ))


-}

minus :: Nat -> Nat -> Nat
minus x Zero = x
minus Zero x = x
minus (Succ (n)) (Succ (m)) = minus n m -- reccursion def of plus function using succ function

contoint :: Nat -> Int 
contoint Zero = 0
contoint (Succ (x)) = 1 + (contoint x)

multiplynumb :: Nat-> Nat -> Nat
multiplynumb Zero _ = Zero
multiplynumb _ Zero = Zero
multiplynumb x (Succ (y)) = plus x (multiplynumb x y)

{-
convtoint :: Nat -> Int -- convert to int
convtoint Zero = 0  -- converts Zero (which is user defined) to actual 0
convtoint (Succ n) = 1 + (convtoint n) 
-}


data Zint = Zint Nat Int
    deriving Show

addzint :: Zint -> Zint -> Zint
addzint (Zint Zero _) x = x
addzint x (Zint Zero _) = x
addzint (Zint n sgn) (Zint m sgm)
    | sgn == sgm = (Zint (plus n m) sgn)
    | (contoint n) > (contoint m) = (Zint (minus n m) (sgn))
    | otherwise = (Zint (minus m n) ((-1)*sgn))


multzint :: Zint -> Zint -> Zint
multzint (Zint Zero _) _ = Zint Zero 1
multzint _ (Zint Zero _) = Zint Zero 1
multzint (Zint n sgn) (Zint m sgm) = (Zint (multiplynumb n m) (sgn*sgm))

subzint :: Zint -> Zint -> Zint
subzint (Zint Zero _) x = x
subzint x (Zint Zero _) = x
subzint (Zint n sgn) (Zint m sgm) = addzint (Zint n sgn) (Zint m ((-1)*sgm))

zconvtoint :: Zint -> Int
zconvtoint (Zint Zero _) = 0
zconvtoint (Zint x sgn) = (sgn)*(contoint x)


main = do
    let x = plus (Succ Zero) (Succ Zero)
    let zp = Zint x 1
    let zn = Zint x (-1)
    print $ zconvtoint zp
    print $ zconvtoint zn 