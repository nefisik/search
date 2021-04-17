#include <iostream>

int main()
{

    auto uuid_generator = boost::uuids::random_generator();

    std::string word;
    //std::ifstream i("../companies.json");

    json j;
    i >> j;
    std::vector<std::string> companiesName = j.get<std::vector<std::string>>();


    std::unordered_map<CompanyOrOwnerName, UUID> company_or_owner_to_uuid;
    std::unordered_map<UUID, Company> companies;

    for(int k = 0; k < companiesName.size(); ++k)
    {
        std::string uuid = boost::uuids::to_string(uuid_generator());
        company_or_owner_to_uuid.insert({companiesName[k], uuid});
        companies.insert({uuid, {companiesName[k]}});
    }

    while(std::getline(std::cin, word))
    {
        auto found_companies_uuid = CompanySearch(company_or_owner_to_uuid, word);
        for(const auto& [_, company_uuid]: found_companies_uuid)
        {
            std::cout << companies[company_uuid].company_name << '\n';
        }

    }
}
