#include <regex>
#include <iostream>


class URI
{
    std::string scheme;
    std::string authority;
    std::string path;
    std::string query;
    std::string fragment;

public:
    /*constexpr*/ URI(std::string const & uri);

    /*constexpr*/ auto get_scheme() const;
    /*constexpr*/ auto get_authority() const;
    /*constexpr*/ auto get_path() const;
    /*constexpr*/ auto get_query() const;
    /*constexpr*/ auto get_fragment() const;

    /*constexpr*/ operator std::string() const;
};

/*constexpr*/ URI::URI(std::string const & uri)
{
    std::smatch match;
    std::regex_match(uri, match, std::regex{R"(^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)"});
    // ^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?

    scheme = match[2];
    authority = match[4];
    path = match[5];
    query = match[7];
    fragment = match[9];
}

/*constexpr*/ auto URI::get_scheme() const { return scheme; }
/*constexpr*/ auto URI::get_authority() const { return authority; }
/*constexpr*/ auto URI::get_path() const { return path; }
/*constexpr*/ auto URI::get_query() const { return query; }
/*constexpr*/ auto URI::get_fragment() const { return fragment; }

/*constexpr*/ URI::operator std::string() const
{
    return scheme + authority + path + query + fragment;
}


int main()
{
    std::vector<std::string> uri_vec
    {
        "https://de.wikipedia.org/wiki/Uniform_Resource_Identifier",
        "ftp://ftp.is.co.za/rfc/rfc1808.txt",
        "file:///C:/Users/Benutzer/Desktop/Uniform%20Resource%20Identifier.html",
        "file:///etc/fstab",
        "geo:48.33,14.122;u=22.5",
        "ldap://[2001:db8::7]/c=GB?objectClass?one",
        "gopher://gopher.floodgap.com",
        "mailto:John.Doe@example.com",
        "sip:911@pbx.mycompany.com",
        "news:comp.infosystems.www.servers.unix",
        "data:text/plain;charset=iso-8859-7,%be%fa%be",
        "tel:+1-816-555-1212",
        "telnet://192.0.2.16:80/",
        "urn:oasis:names:specification:docbook:dtd:xml:4.1.2",
        "git://github.com/rails/rails.git",
        "crid://broadcaster.com/movies/BestActionMovieEver",
        "http://nobody:password@example.org:8080/cgi-bin/script.php?action=submit&pageid=86392001#section_2",
    };

    for (auto const & uri : uri_vec)
    {
        URI u(uri);
        std::string s = u;
        std::cout << s << std::endl;
        std::cout << u.get_scheme() << std::endl;
        std::cout << u.get_authority() << std::endl;
        std::cout << u.get_path() << std::endl;
        std::cout << u.get_query() << std::endl;
        std::cout << u.get_fragment() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
