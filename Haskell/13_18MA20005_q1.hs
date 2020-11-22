-- Name : Altaf Ahmad, Roll no: 18MA20005
data Nat = Zero | Succ Nat 
    deriving Show

plus :: Nat -> Nat -> Nat
plus x Zero = x
plus Zero x = x
plus n (Succ (m)) = Succ (plus n m) 

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
minus (Succ (n)) (Succ (m)) = minus n m 

converttoint :: Nat -> Int 
converttoint Zero = 0
converttoint (Succ (x)) = 1 + (converttoint x)

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

additionzint :: Zint -> Zint -> Zint
additionzint (Zint Zero _) x = x
additionzint x (Zint Zero _) = x
additionzint (Zint n sgn) (Zint m sgm)
    | sgn == sgm = (Zint (plus n m) sgn)
    | (converttoint n) > (converttoint m) = (Zint (minus n m) (sgn))
    | otherwise = (Zint (minus m n) ((-1)*sgn))


multiplyztoint :: Zint -> Zint -> Zint
multiplyztoint (Zint Zero _) _ = Zint Zero 1
multiplyztoint _ (Zint Zero _) = Zint Zero 1
multiplyztoint (Zint n sgn) (Zint m sgm) = (Zint (multiplynumb n m) (sgn*sgm))

subtractztoint :: Zint -> Zint -> Zint
subtractztoint (Zint Zero _) x = x
subtractztoint x (Zint Zero _) = x
subtractztoint (Zint n sgn) (Zint m sgm) = additionzint (Zint n sgn) (Zint m ((-1)*sgm))

convertztoint :: Zint -> Int
convertztoint (Zint Zero _) = 0
convertztoint (Zint x sgn) = (sgn)*(converttoint x)

convertinttonat :: Int -> Nat
convertinttonat 0 = Zero
convertinttonat (x) = (Succ (convertinttonat(x-1)))

gcd'' :: Int -> Int -> Int
gcd'' x 0 = abs x
gcd'' x y = gcd'' b (mod a b)
  where a = abs x
        b = abs y

data Ration = Ration Zint Zint  -- a Rational number is defined by Ration Zint Zint where it denotes p/q where Zint are p and q
    deriving Show

addrational :: Ration -> Ration -> Ration -- adds two rational numbers p1/q1 and p2/q2
addrational (Ration (Zint Zero _) _) p = p
addrational p (Ration (Zint Zero _) _) = p
addrational (Ration p1 q1) (Ration p2 q2) = (Ration (additionzint (multiplyztoint p1 q2) (multiplyztoint p2 q1)) (multiplyztoint q1 q2))

subtractrational :: Ration -> Ration -> Ration -- subtracts two rational numbers p1/q1 and p2/q2
subtractrational (Ration (Zint Zero _) _) p = p
subtractrational p (Ration (Zint Zero _) _) = p
subtractrational (Ration p1 q1) (Ration p2 q2) = (Ration (subtractztoint (multiplyztoint p1 q2) (multiplyztoint p2 q1)) (multiplyztoint q1 q2))

multiplyrational :: Ration -> Ration -> Ration -- multiplies two rational numbers p1/q1 and p2/q2
multiplyrational (Ration (Zint Zero _) _) p = (Ration (Zint Zero 1) (Zint (Succ Zero) 1) )
multiplyrational p (Ration (Zint Zero _) _) = (Ration (Zint Zero 1) (Zint (Succ Zero) 1) )
multiplyrational (Ration p1 q1) (Ration p2 q2) = Ration (multiplyztoint p1 p2) (multiplyztoint q1 q2) 

dividerational :: Ration -> Ration -> Ration -- divides two rational numbers p1/q1 and p2/q2
dividerational (Ration (Zint Zero _) _) p = (Ration (Zint Zero 1) (Zint (Succ Zero) 1) )
dividerational (Ration p1 q1) (Ration p2 q2) = Ration (multiplyztoint p1 q2) (multiplyztoint q1 p2) 

simplestform :: Ration -> Ration -- converts to the simplest form of the Rational number 
simplestform (Ration (Zint a sgna) (Zint b sgnb)) = (Ration (Zint (convertinttonat( (div (converttoint a) (gcd'' (converttoint a) (converttoint b)) )) ) sgna) (Zint (convertinttonat(  (div (converttoint b) (gcd'' (converttoint a) (converttoint b)) ) ) ) sgnb)) --(Ration (Zint convertinttonat( (converttoint a)/(gcd'' (converttoint a) (converttoint b)) ) sgna) (Zint  convertinttonat( (converttoint b)/(gcd'' (converttoint a) (converttoint b)) ) sgnb) )

outputrational :: Ration -> String -- shows the output of the number Ration a b as a/b
outputrational (Ration a b ) = do
    let (Ration a1 b1) = simplestform(Ration a b)
    (show (convertztoint a1)) ++ "/" ++ (show (convertztoint b1))

convertrationtodouble :: Ration -> Double -- this is a function just in case someone wants to convert it to floating points
convertrationtodouble (Ration (Zint Zero _) _) = 0.0
convertrationtodouble (Ration x y) = (fromIntegral (convertztoint x))/(fromIntegral (convertztoint y))

main = do
    let x = convertinttonat 225
    let y = convertinttonat 0
    let ab = Zint x 1
    let bc = Zint y (-1)
    let pq = Ration ab bc
    let rs = Ration bc ab
    putStr "First number, a is "
    print $ convertztoint ab
    putStr "Second number, b is "
    print $ convertztoint bc 
    putStr "The Number formed by a/b is a1 and it is: "
    print $   (outputrational pq)
    putStr "The Number formed by b/a is a2 and it is: "
    print $ (outputrational rs)
    putStr "Now, a1 + a2 = "
    print $  (outputrational (addrational pq rs))
    putStr " = "
    print $  (convertrationtodouble (addrational pq rs))
    putStr "Now, a1 - a2 = "
    print $ outputrational (subtractrational pq rs)
    putStr " = "
    print $  (convertrationtodouble (subtractrational pq rs))
    putStr "Now, a1 * a2 = "
    print $ outputrational (multiplyrational pq rs)
    putStr " = "
    print $  (convertrationtodouble (multiplyrational pq rs))
    putStr "And finally, a1 / a2 = "
    print $ outputrational ((dividerational pq rs)) -- this gives the output of a/b as - a / b
    putStr " = "
    print $  (convertrationtodouble (dividerational pq rs))
