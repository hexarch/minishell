FROM alpine

RUN apk update \
	&& apk add gcc make readline-dev linux-headers libc-dev \
	&& mkdir /opt/minishell

COPY . /opt/minishell

WORKDIR /opt/minishell
RUN mkdir /root/home \
	&& make
CMD ["./minishell"]
