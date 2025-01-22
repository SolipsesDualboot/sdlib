make build docs


rm doc/refman.pdf


cd doc/latex && make pdf && cd ../..


mv doc/latex/refman.pdf doc
