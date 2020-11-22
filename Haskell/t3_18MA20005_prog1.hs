-- Name : Altaf Ahmad, Roll no: 18MA20005
sum_sqr m = head [[a, b, c, d] | a<-[0..m], b<-[0..m], c<-[0..m], d<-[0..m], a*a + b*b + c*c + d*d == m]
main = do
    print $ sum_sqr 23