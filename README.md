# agenda_rpc

- GRUPO: 
    - Denison Barbosa
    - Enzo Gaban
    - Sandy Barros

# Execução

Para executar o trabalho, basta utilizar o Makefile para gerar os executáveis do cliente e do servidor:

``` $ make```

Após gerados os executáveis, inicie o serviço do rpc:
    
``` $ systemctl start rpcbind  ```

Execute o server e, em seguida, o cliente:

``` $ ./server ```

``` $ ./client localhost ```