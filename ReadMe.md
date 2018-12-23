#### Objetivo

​	O Objetivo é fazer um espelho das portas Digitais de 1 ModeMCU em outro ModeMCU, utilizando a comunicação Wireless e o protocolo UDP para a comunicação de ambos.

​	Ideia é verificar a possibilidade de fazer um protocolo de comunicação por fio, vir a funcionar sem fio, por exemplo um Serial rs232.





#### Descrisao

​	Foi utilizando para este projeto uma versão alternativa do ModeMCU, sendo este o LoLin V1, a principio não note diferença como o ModeMCU e o LoLin. Ambos são projetados com o ESP8266

​	As input´s do Cliente, ou seja o modulo que envia os estados das portas, estão configuradas com PullUp internos, bastando colocar nível logico Zero para alterar os estado, sem PullUp externos ou botão para o funcionamento.