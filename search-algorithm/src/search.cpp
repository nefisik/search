#include <search.hpp>

std::multimap<int, UUID> CompanySearch(const std::unordered_map<CompanyOrOwnerName, UUID>& company_or_owner_to_uuid, const std::string& word)
{
    std::multimap<int, UUID> output;

    for(const auto& [name, company_uuid] : company_or_owner_to_uuid)
    {
        auto distance = minDistance(name, word);
        if(distance < name.size()*0.5)
            output.insert({distance, company_uuid});
    }
    return output;
}
