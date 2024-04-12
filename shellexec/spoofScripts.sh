a=$(echo -en "Report.xlsx\x20\x7f.app"); mv Report.xlsx.app $a

a=$(echo -en "Report.xlsx\xe1\x85\xa0.app"); mv Report.xlsx.app $a
