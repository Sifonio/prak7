#include <stdio.h>
#include <stdlib.h>

void check_selinux() {
    printf("==> SELinux статус:\n");
    system("sestatus 2>/dev/null || echo 'SELinux не встановлений'");
}

void check_firewall() {
    printf("\n==> Статус брандмауера:\n");
    system("sudo firewall-cmd --state 2>/dev/null || sudo ufw status 2>/dev/null || echo 'Брандмауер не активний або не встановлений'");
}

void check_root_ssh() {
    printf("\n==> Root SSH доступ:\n");
    system("grep -i '^PermitRootLogin' /etc/ssh/sshd_config 2>/dev/null || echo 'Не знайдено параметра PermitRootLogin'");
}

void check_open_ports() {
    printf("\n==> Відкриті порти:\n");
    system("ss -tuln | grep LISTEN");
}

void check_antivirus() {
    printf("\n==> Антивірус:\n");
    system("which clamscan >/dev/null && echo 'ClamAV встановлено' || echo 'Антивірус не знайдено'");
}

int main() {
    printf("Перевірка конфігурації безпеки системи...\n\n");
    check_selinux();
    check_firewall();
    check_root_ssh();
    check_open_ports();
    check_antivirus();
    printf("\nАналіз завершено.\n");
    return 0;
}

//gcc -Wall 1.c -o 1