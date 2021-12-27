#include <stdio.h>

void createMainPage();

int main(){
    createMainPage();
}

void createMainPage(){
    FILE *mainpage = NULL;

    mainpage = fopen("mainpage.html", "w");


    fprintf(mainpage,
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "<link href=\"style.css\" rel=\"stylesheet\" />\n"
        "<title>IrmaList</title>\n"
        "</head>\n"
        "<body>\n"
        "<h1 style = \"margin-bottom:4px\"> World's Best Store - <span class=\"demo rainbow\">IrmaList</span> </h1>\n"
        "<hr style = \"width:80%; text-align: center\">\n"
        "<h3 style = \"text-align: center; margin-top: 0px; margin-bottom: 0px\"> <a href = "">main page</a> | <a href= \"\">last visited</a> | <a href = \"\">about us</a> | <a href = \" \"> contact us </a></h3>\n"
        "<hr style = \"width: 80%; text-align: center\">\n"
        "<h3 style = \"margin-bottom:12px;margin-left: 24px\"> Most viewed posts: </h3>\n"
        "<table>\n"
        "<tr>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href = \" \"> <img src = \"powder.jpg\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href = \" \"> <img src = \"stonks.png\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href =\" \"> <img src = \"plus.png\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "</tr>\n"
        "<tr>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> null </a> </td>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> null </a> </td>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> browse more... </a> </td>\n"
        "</tr>\n"
        "</table> \n"
        "<col style = \"width: 12px\"/>\n"
        "<h3 style = \"margin-top:48px;margin-bottom:12px;margin-left: 24px;\"> Most recent posts: </h3>\n"
        "<table style = \"table-layout:fixed\">\n"
        "<tr>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href = \" \"> <img src = \"stonks.png\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href = \" \"> <img src = \"toplawyer.jpg\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "<td style = \"padding-left:12px; padding-right:12px; border:1px solid black; width:100px\"> <a href = \" \"> <img src = \"plus.png\" style = \"object-fit:scale-down\" width = \"250\" height = \"150\"> </a> </td>\n"
        "</tr>\n"
        "<tr>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> null </a> </td>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> null </a> </td>\n"
        "<td style = \"padding-left:12px\"> <a href = \" \"> browse more... </a> </td>\n"
        "</tr>\n"
        "</table> \n"
        "<p id=\"copyright\">&copy; 2021 Adomas, Tomas, Matas, Domas</p>\n"
        "</body>\n"
        "</html>\n"
    );

    fclose(mainpage);
}
