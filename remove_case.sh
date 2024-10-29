
#!/bin/bash

# ls -latSh chr19_pengxin_*.txt
# grep -H "Elapsed (wall clock) time" casestudy_16_100000_*.txt
# grep -c '^' chr19_pengxin_16_1.txt
# wc -l chr19_pengxin_16_1.txt


# # 16.txt
# awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_16_1.txt  > temp && mv temp chr19_pengxin_16_1.txt

# awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==2 { print substr($0,1,24629846) substr($0, 27729847)} NR!=2' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==3 { print substr($0,1,24629955) substr($0, 27729956)} NR!=3' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==4 { print substr($0,1,24629896) substr($0, 27729897)} NR!=4' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==5 { print substr($0,1,24630155) substr($0, 27730156)} NR!=5' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==6 { print substr($0,1,24629508) substr($0, 27729509)} NR!=6' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==7 { print substr($0,1,24629521) substr($0, 27729522)} NR!=7' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==8 { print substr($0,1,24629760) substr($0, 27729761)} NR!=8' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==9 { print substr($0,1,24629784) substr($0, 27729785)} NR!=9' chr19_pengxin_16.txt  > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==10 {print substr($0,1,24630015) substr($0, 27730016)} NR!=10' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==11 {print substr($0,1,24629363) substr($0, 27729364)} NR!=11' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==12 {print substr($0,1,24630119) substr($0, 27730120)} NR!=12' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==13 {print substr($0,1,24630160) substr($0, 27730161)} NR!=13' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==14 {print substr($0,1,24629398) substr($0, 27729399)} NR!=14' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==15 {print substr($0,1,24630000) substr($0, 27730001)} NR!=15' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt
# awk 'NR==16 {print substr($0,1,24629707) substr($0, 27729708)} NR!=16' chr19_pengxin_16.txt > temp && mv temp chr19_pengxin_16.txt


# # 32.txt
# awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_32_1.txt  > temp && mv temp chr19_pengxin_32_1.txt

# awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==2 { print substr($0,1,24629846) substr($0, 27729847)} NR!=2' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==3 { print substr($0,1,24629955) substr($0, 27729956)} NR!=3' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==4 { print substr($0,1,24629896) substr($0, 27729897)} NR!=4' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==5 { print substr($0,1,24630155) substr($0, 27730156)} NR!=5' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==6 { print substr($0,1,24629508) substr($0, 27729509)} NR!=6' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==7 { print substr($0,1,24629521) substr($0, 27729522)} NR!=7' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==8 { print substr($0,1,24629760) substr($0, 27729761)} NR!=8' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==9 { print substr($0,1,24629784) substr($0, 27729785)} NR!=9' chr19_pengxin_32.txt  > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==10 {print substr($0,1,24630015) substr($0, 27730016)} NR!=10' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==11 {print substr($0,1,24629363) substr($0, 27729364)} NR!=11' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==12 {print substr($0,1,24630119) substr($0, 27730120)} NR!=12' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==13 {print substr($0,1,24630160) substr($0, 27730161)} NR!=13' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==14 {print substr($0,1,24629398) substr($0, 27729399)} NR!=14' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==15 {print substr($0,1,24630000) substr($0, 27730001)} NR!=15' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==16 {print substr($0,1,24629707) substr($0, 27729708)} NR!=16' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==17 {print substr($0,1,24629377) substr($0, 27729378)} NR!=17' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==18 {print substr($0,1,24629692) substr($0, 27729693)} NR!=18' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==19 {print substr($0,1,24629601) substr($0, 27729602)} NR!=19' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==20 {print substr($0,1,24629167) substr($0, 27729168)} NR!=20' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==21 {print substr($0,1,24629424) substr($0, 27729425)} NR!=21' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==22 {print substr($0,1,24629306) substr($0, 27729307)} NR!=22' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==23 {print substr($0,1,24629820) substr($0, 27729821)} NR!=23' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==24 {print substr($0,1,24629404) substr($0, 27729405)} NR!=24' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==25 {print substr($0,1,24630340) substr($0, 27730341)} NR!=25' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==26 {print substr($0,1,24629500) substr($0, 27729501)} NR!=26' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==27 {print substr($0,1,24630056) substr($0, 27730057)} NR!=27' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==28 {print substr($0,1,24629627) substr($0, 27729628)} NR!=28' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==29 {print substr($0,1,24630094) substr($0, 27730095)} NR!=29' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==30 {print substr($0,1,24629756) substr($0, 27729757)} NR!=30' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==31 {print substr($0,1,24629282) substr($0, 27729283)} NR!=31' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt
# awk 'NR==32 {print substr($0,1,24629718) substr($0, 27729719)} NR!=32' chr19_pengxin_32.txt > temp && mv temp chr19_pengxin_32.txt



# 64.txt
awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_64_1.txt  > temp && mv temp chr19_pengxin_64_1.txt

awk 'NR==1 { print substr($0,1,24630449) substr($0, 27730450)} NR!=1' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==2 { print substr($0,1,24629846) substr($0, 27729847)} NR!=2' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==3 { print substr($0,1,24629955) substr($0, 27729956)} NR!=3' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==4 { print substr($0,1,24629896) substr($0, 27729897)} NR!=4' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==5 { print substr($0,1,24630155) substr($0, 27730156)} NR!=5' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==6 { print substr($0,1,24629508) substr($0, 27729509)} NR!=6' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==7 { print substr($0,1,24629521) substr($0, 27729522)} NR!=7' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==8 { print substr($0,1,24629760) substr($0, 27729761)} NR!=8' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==9 { print substr($0,1,24629784) substr($0, 27729785)} NR!=9' chr19_pengxin_64.txt  > temp && mv temp chr19_pengxin_64.txt
awk 'NR==10 {print substr($0,1,24630015) substr($0, 27730016)} NR!=10' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==11 {print substr($0,1,24629363) substr($0, 27729364)} NR!=11' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==12 {print substr($0,1,24630119) substr($0, 27730120)} NR!=12' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==13 {print substr($0,1,24630160) substr($0, 27730161)} NR!=13' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==14 {print substr($0,1,24629398) substr($0, 27729399)} NR!=14' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==15 {print substr($0,1,24630000) substr($0, 27730001)} NR!=15' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==16 {print substr($0,1,24629707) substr($0, 27729708)} NR!=16' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==17 {print substr($0,1,24629377) substr($0, 27729378)} NR!=17' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==18 {print substr($0,1,24629692) substr($0, 27729693)} NR!=18' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==19 {print substr($0,1,24629601) substr($0, 27729602)} NR!=19' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==20 {print substr($0,1,24629167) substr($0, 27729168)} NR!=20' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==21 {print substr($0,1,24629424) substr($0, 27729425)} NR!=21' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==22 {print substr($0,1,24629306) substr($0, 27729307)} NR!=22' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==23 {print substr($0,1,24629820) substr($0, 27729821)} NR!=23' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==24 {print substr($0,1,24629404) substr($0, 27729405)} NR!=24' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==25 {print substr($0,1,24630340) substr($0, 27730341)} NR!=25' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==26 {print substr($0,1,24629500) substr($0, 27729501)} NR!=26' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==27 {print substr($0,1,24630056) substr($0, 27730057)} NR!=27' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==28 {print substr($0,1,24629627) substr($0, 27729628)} NR!=28' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==29 {print substr($0,1,24630094) substr($0, 27730095)} NR!=29' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==30 {print substr($0,1,24629756) substr($0, 27729757)} NR!=30' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==31 {print substr($0,1,24629282) substr($0, 27729283)} NR!=31' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==32 {print substr($0,1,24629718) substr($0, 27729719)} NR!=32' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==33 {print substr($0,1,24629633) substr($0, 27729634)} NR!=33' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==34 {print substr($0,1,24629645) substr($0, 27729646)} NR!=34' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==35 {print substr($0,1,24629365) substr($0, 27729366)} NR!=35' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==36 {print substr($0,1,24629588) substr($0, 27729589)} NR!=36' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==37 {print substr($0,1,24629568) substr($0, 27729569)} NR!=37' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==38 {print substr($0,1,24629586) substr($0, 27729587)} NR!=38' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==39 {print substr($0,1,24629781) substr($0, 27729782)} NR!=39' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==40 {print substr($0,1,24629840) substr($0, 27729841)} NR!=40' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==41 {print substr($0,1,24629800) substr($0, 27729801)} NR!=41' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==42 {print substr($0,1,24629316) substr($0, 27729317)} NR!=42' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==43 {print substr($0,1,24629994) substr($0, 27729995)} NR!=43' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==44 {print substr($0,1,24629587) substr($0, 27729588)} NR!=44' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==45 {print substr($0,1,24629789) substr($0, 27729790)} NR!=45' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==46 {print substr($0,1,24629795) substr($0, 27729796)} NR!=46' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==47 {print substr($0,1,24629679) substr($0, 27729680)} NR!=47' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==48 {print substr($0,1,24629236) substr($0, 27729237)} NR!=48' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==49 {print substr($0,1,24629588) substr($0, 27729589)} NR!=49' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==50 {print substr($0,1,24629787) substr($0, 27729788)} NR!=50' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==51 {print substr($0,1,24629587) substr($0, 27729588)} NR!=51' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==52 {print substr($0,1,24629463) substr($0, 27729464)} NR!=52' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==53 {print substr($0,1,24629599) substr($0, 27729600)} NR!=53' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==54 {print substr($0,1,24629001) substr($0, 27729002)} NR!=54' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==55 {print substr($0,1,24629787) substr($0, 27729788)} NR!=55' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==56 {print substr($0,1,24629250) substr($0, 27729251)} NR!=56' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==57 {print substr($0,1,24629839) substr($0, 27729840)} NR!=57' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==58 {print substr($0,1,24629660) substr($0, 27729661)} NR!=58' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==59 {print substr($0,1,24630576) substr($0, 27730577)} NR!=59' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==60 {print substr($0,1,24629779) substr($0, 27729780)} NR!=60' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==61 {print substr($0,1,24629468) substr($0, 27729469)} NR!=61' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==62 {print substr($0,1,24629401) substr($0, 27729402)} NR!=62' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==63 {print substr($0,1,24629810) substr($0, 27729811)} NR!=63' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt
awk 'NR==64 {print substr($0,1,24629822) substr($0, 27729823)} NR!=64' chr19_pengxin_64.txt > temp && mv temp chr19_pengxin_64.txt


