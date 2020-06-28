#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace raffer // interface
{

auto split(std::string const & str, char delim = ' ') -> std::vector<std::string>;

} // namespace raffer

namespace raffer // implementation
{

auto split(std::string const & str, char delim) -> std::vector<std::string>
{
	auto words = std::vector<std::string>{};
	auto iss = std::istringstream{str};
	
	std::string s;
	while (getline(iss, s, delim))
		words.push_back(s);
	
	return words;
}

} // namespace raffer



namespace raffer // interface
{

class personal_name
{
	std::string last_name, first_name;
	
public:
	personal_name(std::string full_name = "");
	personal_name(std::string last_name, std::string first_name);
	
	[[nodiscard]] auto get_last_name() const -> std::string;
	auto set_last_name(std::string const & last_name) -> void;
	auto set_last_name(std::string && last_name) noexcept -> void;
	
	[[nodiscard]] auto get_first_name() const -> std::string;
	auto set_first_name(std::string const & first_name) -> void;
	auto set_first_name(std::string && first_name) noexcept -> void;
	
	[[nodiscard]] operator std::string() const;
};

std::ostream & operator<<(std::ostream & os, personal_name const & pn);

} // namespace raffer



namespace raffer // implementation
{

personal_name::personal_name(std::string full_name)
{
	auto full_name_iss = std::istringstream{std::move(full_name)};
	getline(full_name_iss, last_name, ' ');
	getline(std::move(full_name_iss), first_name);
}

personal_name::personal_name(std::string last_name, std::string first_name)
: last_name{std::move(last_name)}, first_name(std::move(first_name)) {}

auto personal_name::get_last_name() const -> std::string
{ return last_name; }
auto personal_name::set_last_name(std::string const & last_name) -> void
{ this->last_name = last_name; }
auto personal_name::set_last_name(std::string && last_name) noexcept -> void
{ this->last_name = std::move(last_name); }

auto personal_name::get_first_name() const -> std::string
{ return first_name; }
auto personal_name::set_first_name(std::string const & first_name) -> void
{ this->first_name = first_name; }
auto personal_name::set_first_name(std::string && first_name) noexcept -> void
{ this->first_name = std::move(first_name); }

personal_name::operator std::string() const
{ return get_last_name() + " " + get_first_name(); }

std::ostream & operator<<(std::ostream & os, personal_name const & pn)
{ return os << std::string(pn); }

} // namespace raffer




namespace raffer // interface
{

class person
{
	personal_name name;
	
public:
	auto get_name() const -> personal_name;
	auto get_last_name = name.get_last_name;
};

} // namespace raffer

namespace raffer // implementation
{

auto person::get_name() const -> personal_name
{ return name; }

} // namespace raffer



auto main() -> int
{
	/*raffer::personal_name name("Hallo", "Welt");
	
	std::string s = name;
	std::cout << s;
	std::cout << name << std::endl;
	
	raffer::personal_name name2{"Raffer  Paul"};
	
	std::cout << name2.get_first_name();*/
	
	
	raffer::person per;
	std::cout << per.get_name();
}
