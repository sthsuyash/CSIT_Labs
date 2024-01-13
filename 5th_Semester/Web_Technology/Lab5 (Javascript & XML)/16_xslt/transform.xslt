<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <head>
                <title>Library Catalog</title>
            </head>
            <body>
                <h1>Library Catalog</h1>
                <ul>
                    <xsl:apply-templates select="library/book"/>
                </ul>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="book">
        <li>
            <strong>Title:</strong> <xsl:value-of select="title"/><br/>
            <strong>Author:</strong> <xsl:value-of select="author"/>
        </li>
    </xsl:template>

</xsl:stylesheet>
