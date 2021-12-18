#include <stdio.h>
#include <stdlib.h>

void compileAboutUs(FILE *aboutUs)
{
    fprintf
    (aboutUs,
        "<!DOCTYPE html>\n"
        "<html>\n"
        "    <head>\n"
        "    <link href=\"style.css\" rel=\"stylesheet\" />\n"
        "    <title> About Us - IrmaList </title>\n"

        "        <style>\n"
                     /* Headers */
        "            h1{\n"
        "                margin-bottom:4px;\n"
        "                text-align: center;\n"
        "            }\n"
        "            h3{\n"
        "                text-align: center;\n"
        "                margin-top: 0px;\n"
        "                margin-bottom: 0px;\n"				
        "            }\n"

                    /*Table elements*/
        "            table{\n"
        "                font-size: 24px;\n"
        "                width: 75%;\n"
        "                margin-left:auto;\n"
        "                margin-right:auto;\n"
        "            }\n"
        "            td{\n"
        "                margin-right: 5%;\n"
        "            }\n"
        "            #defineIrmalist{\n"
        "                text-align: center;\n"
        "                font-size: 36px;\n"
        "            }\n"
        "            #tableText{\n"
        "                text-align: center;\n"
        "                vertical-align: top;\n"
        "            }\n"
                    
                    /*Seperating lines*/
        "            hr{\n"
        "                width:80%;\n" 
        "                text-align: center;\n"
        "            }\n"

                    /*Image*/
        "            img{\n"
        "                width: 350px;\n"
        "            }\n"

        "        </style>\n"
        "    </head>\n"

        "    <body>\n"
        "        <h1>\n"
        "            World's Best Store - <span class=\"demo rainbow\">IrmaList</span>\n"
        "        </h1>\n"

        "        <hr>\n"
        "        <h3>\n"
        "            <a href = \"mainpage.html\">Main Page</a> |\n"
        "            <a href = \"website.html\">Last Visited</a> |\n"
        "            <a href = \"aboutus.html\">About Us</a> |\n"
        "            <a href = \"contact.html\">Contact Us</a>\n"
        "        </h3>\n"
        "        <hr>\n"
        "        <br>\n"

        "        <table>\n"
        "            <tr>\n"
        "                <td id=\"defineIrmalist\" colspan = \"2\">\n"
        "                    What is <span class=\"demo rainbow\">IrmaList</span>?\n"
        "                    <br>\n"
        "                    <br>\n"
        "                </td>\n"
        "            </tr>\n"
        "            <tr>\n"
        "                <td id=\"tableText\">\n"
        "                    <span class=\"demo rainbow\">IrmaList</span>\n"
        "                    (stands for: Interactive Reasonable Marketplace Agency)\n"
        "                    is an advertisement website which puts extreme emphasis on user ability to customize their postings to our website.\n"
        "                    This is due to the belief shared by our team that to present your offer properly is a vital skill,\n"
        "                    especially nowadays when other platforms of similar purpose are flooded\n"
        "                    with low quality ads that do not properly reflect the product being sold.\n"
        "                    Our mission statement is to combat the stigma towards second hand purchases\n"
        "                    by offering the tools to professionally showcase one's offerings.\n"
        "                </td>\n"
        "                <td>\n"
        "                    <img src = \"founders.jpg\"/>\n"
        "                    <p>\n"
        "                        Photo taken during the first meeting of the\n"
        "                        <span class=\"demo rainbow\">IrmaList</span>team.\n"
        "                    </p>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </table>\n"
            
        "        <br>\n"
        "        <br>\n"
        "        <p id=\"copyright\">&copy; 2021 Adomas, Tomas, Matas, Domas</p>\n"
        "    </body>\n"

        "</html>\n"
    );

    return;
}

int main()
{
    FILE *aboutUs = fopen("aboutus.html", "w");

    if(!aboutUs){
        printf("Error 404. Page not found.");
        return EXIT_FAILURE;
    }

    compileAboutUs(aboutUs);

    fclose(aboutUs);
    return EXIT_SUCCESS;
}
