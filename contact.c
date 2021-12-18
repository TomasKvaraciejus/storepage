#include <stdio.h>

void compileContacts();

int main(){
    compileContacts();
}

void compileContacts(){

    FILE *contacts;

    contacts = fopen("contacts1.html", "w");

    fprintf(contacts, 
        "<!DOCTYPE html>\n"
        "<html>\n"
        "    <link href=\"style.css\" rel=\"stylesheet\" />\n"
        "    <title>Contacts - IrmaList</title>\n"
        "    <style>\n"
        "      p {\n"
        "        text-align: center;\n"
        "      }\n"
        "       td {\n"
        "        font-size: 24px;\n"
        "      }\n"
        "      h1 {\n"
        "        margin-bottom: 4px;\n"
        "        text-align: center;\n"
        "      }\n"
        "      hr{\n"
        "        width: 80%; \n"
        "        text-align: center;\n"
        "      }\n"
        "    </style>\n"
        "  </head>\n"
        "    <body>\n"
        "      <h1>\n"
        "        World's Best Store - <span class=\"demo rainbow\">IrmaList</span>\n"
        "      </h1>\n"
        "      <hr/>\n"
        "      <h3 style=\"text-align: center; margin-top: 0px; margin-bottom: 0px\">\n"
        "        <a href=\"mainpage.html\">main page</a> |\n"
        "        <a href=\"website.html\">last visited</a> |\n"
        "        <a href=\"aboutus.html\">about us</a> |\n"
        "        <a href=\"contact.html\"> contact us </a>\n"
        "      </h3>\n"
        "      <hr/>\n"
        "      <br/>\n"
        "      <h1>Contacts</h1>\n"
        "      <p>\n"
        "        Coordinator: <br />Domas Nemanius<br />Telephone number: +370********\n"
        "        <br />Email address:\n"
        "      </p>\n"
        "      <p>\n"
        "        Lead Designer: <br />Adomas Vensas<br />Telephone number: +370********\n"
        "        <br />Email address:\n"
        "      </p>\n"
        "      <p>\n"
        "        Chief Architect: <br />Tomas Kvaraciejus<br />Telephone number:\n"
        "        +370******** <br />Email address:\n"
        "      </p>\n"
        "      <p>/n"
        "        Lead Developer: <br />Matas Šamšonas<br />Telephone number: +370********\n"
        "        <br />Email address:\n"
        "      </p>\n"
        "      <p>\n"
        "        Company headquarters: <br />Didlaukio g. 47, Vilnius 08303<br />Telephone\n"
        "        number: +370********\n"
        "      </p>\n"
        "    </body>\n"
        "    <br />\n"
        "    <br />\n"
        "    <p id=\"copyright\">&copy; 2021 Adomas, Tomas, Matas, Domas</p>\n"
        "  </head>\n"
        "</html>\n"
        );

    fclose(contacts);

}
