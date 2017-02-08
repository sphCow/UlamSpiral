set term pngcairo size 4096,4096 
set out 'ulam_4096.png'

set size sq
unse key
unse tics
unse border
unse colorbox
set palette model RGB defined ( 0 'black', 1 'yellow' )
plot 'ulam_4096.out' i 0 matrix w image
